vars= pwd echo cp mv


%: %.c
	gcc -o $@ $<

.PHONY: clean
clean:
	@rm $(vars)
