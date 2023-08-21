ENTRY(start)

SECTIONS
{
	. = 10M;

	.boot :
	{
		KEEP(*(.multiboot_header))
	}

	.text :
	{
		*(.text)
	}
}
