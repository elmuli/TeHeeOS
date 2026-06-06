#!/bin/bash
# copy-with-deps.sh

BINARY=$1
DEST=${2:-.}

mkdir -p $DEST/usr/lib

echo "Copying $BINARY to $DEST/usr/bin/"
cp $BINARY $DEST/usr/bin/

echo "Finding dependencies..."
ldd $BINARY | grep "=>" | awk '{print $3}' | while read lib; do
    if [ -z "$lib" ] || [ ! -f "$lib" ]; then
        echo "  Skipping $lib (not found)"
        continue
    fi

    # Get the real file (resolve symlinks)
    REAL=$(readlink -f "$lib")
    FILENAME=$(basename "$REAL")
    LINKNAME=$(basename "$lib")

    echo "  Copying $FILENAME (from $REAL)"

    # Copy actual file
    cp "$REAL" $DEST/usr/lib/$FILENAME

    # Create symlinks if different
    if [ "$FILENAME" != "$LINKNAME" ]; then
        cd $DEST/usr/lib/
        ln -sf $FILENAME $LINKNAME
        cd - >/dev/null
        echo "    Symlink: $LINKNAME -> $FILENAME"
    fi
done

echo "Done!"
