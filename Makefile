include config.mk

ifeq ($(WIN32),1)
	O += .exe
endif

all: $(O)

$(O):passwd-gen.c
	@echo "  (CC)    $< --> $@"
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo "  (CLEAN)  $(O)"
	@rm -f $(O)

.PHONY: clean
