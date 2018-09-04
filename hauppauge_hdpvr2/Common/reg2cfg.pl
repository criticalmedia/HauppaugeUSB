#!/usr/bin/perl

while(my $s = <>) {
	if($s=~/^\s*"([^"]+)"=dword:([0-9a-fA-F]+)\s*$/) {
		print "$1=".hex($2)."\n";
	}
}
