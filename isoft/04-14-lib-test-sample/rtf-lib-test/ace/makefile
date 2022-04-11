OBJDIR = ../../test_bin/ace

ace_test: *.cpp
	g++ -lACE $+ -o $@
	strip $@
	mv $@ $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

