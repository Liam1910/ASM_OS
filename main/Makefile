kernel_source_files := $(shell find src/impl/kernel -name *.c)
x86_64_c_source_files := $(shell find src/impl/x86_64 -name *.c)
x86_64_asm_source_files := $(shell find src/impl/x86_64 -name *.asm)

kernel_object_files := $(patsubst src/impl/kernel/%.c, build/kernel/%.o, $(kernel_source_files))
x86_64_c_object_files := $(patsubst src/impl/x86_64/%.c, build/x86_64/%.o, $(x86_64_c_source_files))
x86_64_asm_object_files := $(patsubst src/impl/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

x86_64_object_files := $(x86_64_c_object_files) $(x86_64_asm_object_files)

$(kernel_object_files): build/kernel/%.o : src/impl/kernel/%.c
	mkdir -p $(dir $@) && \
	gcc -c -I src/intf -ffreestanding $(patsubst build/kernel/%.o, src/impl/kernel/%.c, $@) -o $@

$(x86_64_c_object_files): build/x86_64/%.o : src/impl/x86_64/%.c
	mkdir -p $(dir $@) && \
	gcc -c -I src/intf -ffreestanding $(patsubst build/x86_64/%.o, src/impl/x86_64/%.c, $@) -o $@

$(x86_64_asm_object_files): build/x86_64/%.o : src/impl/x86_64/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/impl/x86_64/%.asm, $@) -o $@


.PHONY: build
.PHONY: remove
.PHONY: run
build: $(kernel_object_files) $(x86_64_object_files)
	$(MAKE) -C /home/liam/Music/OS-ALL/custom-os/testMode/ build_tstmd
	$(MAKE) -C /home/liam/Music/OS-ALL/custom-os/safeMode/ build_sfmd
	mkdir -p dist/x86_64 && \
	ld -n -o dist/x86_64/main.bin -T targets/x86_64/linker.ld $(kernel_object_files) $(x86_64_object_files) && \
	cp dist/x86_64/main.bin targets/x86_64/iso/boot/kernel/main.bin && \
	cp -r src/ targets/x86_64/iso && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso

remove: $(kernel_object_files) $(x86_64_object_files)
	$(MAKE) -C /home/liam/Music/OS-ALL/custom-os/safeMode/ remove_sfmd
	$(MAKE) -C /home/liam/Music/OS-ALL/custom-os/testMode/ remove_tstmd
	rm -r build && \
	rm -r dist && \
	rm targets/x86_64/iso/boot/kernel/main.bin && \
	rm -r targets/x86_64/iso/src



run: $(kernel_object_files) $(x86_64_object_files)
	make build
	
	qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso

	make remove
	
