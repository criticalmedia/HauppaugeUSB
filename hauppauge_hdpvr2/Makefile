all:
	cd ./TestApp;\./rebuild.sh ${cpu}

install:
	cd ./TestApp;\./pack.sh

clean:
	$(MAKE) -C ./TestApp/build-ADV7842 clean
	$(MAKE) -C ./TestApp/build clean

.PHONY: all install clean
