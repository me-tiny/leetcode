CXX      := clang++
CXXFLAGS := -std=c++23 -Wall -Wextra -g -O2 -I include
ifdef D
  CXXFLAGS := -std=c++23 -Wall -Wextra -g -O0 -fsanitize=address,undefined -I include
endif

.PHONY: run clean

run:
ifndef F
	@echo "Usage: make run F=problems/XXXX-name/sol.cpp"
	@echo "       make run F=problems/XXXX-name/sol.cpp D=1  (debug/sanitizers)"
	@exit 1
endif
	@$(CXX) $(CXXFLAGS) $(F) -o /tmp/lc_out && /tmp/lc_out

clean:
	@rm -f /tmp/lc_out
