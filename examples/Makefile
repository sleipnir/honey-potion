EXAMPLES := $(shell find . -maxdepth 1 -type d ! -name '_*' ! -name 'frontends' ! -name '_build' ! -name '.' | sed 's|./||')

.PHONY: all $(EXAMPLES)

all:
	@for dir in $(EXAMPLES); do \
	  if [ -f "$$dir/mix.exs" ]; then \
	    echo "Compiling $$dir"; \
	    (cd $$dir && mix format && mix deps.get && mix compile) || echo "Failed to compile $$dir"; \
	  fi; \
	done

$(EXAMPLES):
	@if [ -f "$@/mix.exs" ]; then \
	  echo "Compiling $@"; \
	  cd $@ && mix format && mix deps.get && mix compile; \
	else \
	  echo "No mix.exs found in $@"; \
	fi
