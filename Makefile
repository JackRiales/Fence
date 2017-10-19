ROM_CONFIG  = nrom_128_horz.cfg
CRT_LIB     = asm/neslib/crt0.s
CRT_OBJ     = build/neslib.o
RUNTIME_LIB = build/nes.lib
ASM         = ca65
ASM_O       = build
CC          = cc65
CC_S        = source
CC_O        = asm
CC_FLAGS    = -Oi
CC_INC      = include
CC_META     = meta
LD          = ld65
LD_O        = bin
BIN         = bin/fence.nes

all: $(BIN) ${CRT_OBJ}

# Compile neslib
$(CRT_OBJ):
	$(ASM) -o $(CRT_OBJ) $(CRT_LIB)

# Compile to 6502 asm
%.s: %.c
	$(CC) $(CC_FLAGS) -I $(CC_INC) -I $(CC_META) -o $(CC_O) $< --add-source

# Compile from asm to binary
%.o: %.s
	$(ASM) -o $(ASM_O) $<

# Link object binaries
$(BIN): $(CRT_OBJ) $(ROM_CONFIG) $(RUNTIME_LIB)
	$(LD) -C $(ROM_CONFIG) -o $(BIN) $(ASM_O)/*.o $(RUNTIME_LIB)

# Cleanup
clean:
	rm -f $(BIN) $(ASM_O)/*.o