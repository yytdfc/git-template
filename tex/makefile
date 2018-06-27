SECS = $(wildcard ./sections/*.tex)
IMGS = $(wildcard ./images/*)

.PHONY: all clean cleanall

all:
	make main.pdf
	open main.pdf

main.pdf: main.tex main.bbl ${SECS} ${IMGS}
	pdflatex main.tex

main.bbl: main.bib main.tex ${SECS}
	pdflatex main.tex
	bibtex main
	pdflatex main.tex

cleanall: clean
	-rm main.pdf main.dvi

clean:
	-rm main.aux main.bbl main.log main.blg main.out

