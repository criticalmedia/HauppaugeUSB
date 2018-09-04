#ifndef __AVOUTPUT_H_
#define __AVOUTPUT_H_

#include <functional>

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "winwrap.h"

//Stub yet

class DataTransfer {
 public:
	using callback_t = std::function<void(void*, size_t)>;

 protected:
	int m_fd;
	bool m_own_fd;
	callback_t m_cb;
	bool m_use_cb;

 public:
        DataTransfer(): m_fd(-1), m_own_fd(false), m_use_cb(false) {}
	~DataTransfer() {
		if(m_fd > 0) ::close(m_fd);
	}

	bool setFile(const char *fn) {
		if(m_own_fd && (m_fd > 0)) ::close(m_fd);
		if(!fn) return true;
		m_fd = ::open(fn, O_WRONLY | O_TRUNC | O_CREAT, 0666);
		return m_own_fd = (m_fd >= 0);
	}

	void setFD(int fd) {
		if(m_own_fd && (m_fd > 0)) ::close(m_fd);
		m_own_fd = false;
		m_fd = fd;
	}

	void setCB(callback_t & cb) { m_cb = cb; m_use_cb = true; }

	void write(void *data, size_t len) {
	        if(m_use_cb) m_cb(data, len);
		if(m_fd < 0) return;
		::write(m_fd, data, len);
	}

	static VOID static_BufferComplete(void *p_context, void *p_data, size_t transfer_size) {
		DataTransfer *o = (DataTransfer*)p_context;
		if(o) o->write(p_data, transfer_size);
	}
};

#endif
