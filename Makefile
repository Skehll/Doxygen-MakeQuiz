all: build doczip collegemain

clean:
	rm -rf *.o *~ *.class a.out html/ latex/ config config.bak *.tgz

build:
	g++ collegemain.cc course.cc college.cc -o myexe

doc:
	html/index.html

collegemain: collegemain.o course.o college.o
	g++ collegemain.o course.o college.o -o collegemain

collegemain.o: collegemain.cc
	g++ -c collegemain.cc

course.o: course.cc
	g++ -c course.cc

college.o: college.cc
	g++ -c college.cc

html/index.html: collegemain.cc course.cc college.cc
ifneq ("$(wildcard config)","")
	doxygen -u config
else
	doxygen -g config
endif
	doxygen config

myexe:
	g++ collegemain.cc course.cc college.cc -o myexe

doczip:	doc.tgz

doc.tgz: html/index.html
	tar -cvzf doc.tgz html/
