OBJDIR = ../../test_bin/iniparser

iniparser_test: *.c
	g++ -liniparser $+ -o $@
	mv $@ $(OBJDIR)

clean:
		rm -rf $(OBJDIR)
