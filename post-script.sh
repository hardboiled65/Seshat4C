#!/bin/sh

VERSION=`cat Cargo.toml | grep version | sed -r 's/version = "([0-9]+)\.([0-9]+)\.([0-9]+)"/\1.\2.\3/'`
VERSION_MAJOR=`echo $VERSION | cut -d'.' -f 1`
VERSION_MINOR=`echo $VERSION | cut -d'.' -f 2`
VERSION_PATCH=`echo $VERSION | cut -d'.' -f 3`

if [[ -L target/debug/libseshat.so ]]
then
	echo "Delete symlink: libseshat.so"
	rm target/debug/libseshat.so
fi

if [[ -L target/debug/libseshat.so.$VERSION_MAJOR ]]
then
	rm target/debug/libseshat.so.$VERSION_MAJOR
fi

if [[ -L target/debug/libseshat.so.$VERSION_MAJOR.$VERSION_MINOR ]]
then
	rm target/debug/libseshat.so.$VERSION_MAJOR.$VERSION_MINOR
fi

if [[ -f target/debug/libseshat.so ]]
then
	mv target/debug/libseshat.so target/debug/libseshat.so.$VERSION
	ln -s libseshat.so.$VERSION_MAJOR.$VERSION_MINOR.$VERSION_PATCH target/debug/libseshat.so.$VERSION_MAJOR.$VERSION_MINOR
	ln -s libseshat.so.$VERSION_MAJOR.$VERSION_MINOR target/debug/libseshat.so.$VERSION_MAJOR
	ln -s libseshat.so.$VERSION_MAJOR target/debug/libseshat.so
fi
