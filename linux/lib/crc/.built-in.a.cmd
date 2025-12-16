savedcmd_lib/crc/built-in.a := rm -f lib/crc/built-in.a;  printf "lib/crc/%s " tests/built-in.a | xargs ar cDPrST lib/crc/built-in.a
