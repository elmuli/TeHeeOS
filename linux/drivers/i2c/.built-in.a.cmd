savedcmd_drivers/i2c/built-in.a := rm -f drivers/i2c/built-in.a;  printf "drivers/i2c/%s " algos/built-in.a busses/built-in.a muxes/built-in.a | xargs ar cDPrST drivers/i2c/built-in.a
