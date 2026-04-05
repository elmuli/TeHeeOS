savedcmd_arch/x86/boot/compressed/vmlinux.bin.xz := { cat arch/x86/boot/compressed/vmlinux.bin | sh ./scripts/xz_wrap.sh; printf \\300\\112\\302\\000; } > arch/x86/boot/compressed/vmlinux.bin.xz
