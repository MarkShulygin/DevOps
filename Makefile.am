AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = devops
devops_SOURCES = main.cpp FuncA.cpp FuncA.h
dist_man_MANS = devops.1


.PHONY: deb
deb:
	make DESTDIR=$(CURDIR)/deb install
