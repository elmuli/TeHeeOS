savedcmd_drivers/pci/built-in.a := rm -f drivers/pci/built-in.a;  printf "drivers/pci/%s " controller/built-in.a switch/built-in.a | xargs ar cDPrST drivers/pci/built-in.a
