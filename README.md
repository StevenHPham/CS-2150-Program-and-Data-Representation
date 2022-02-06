# CS-2150-Program-and-Data-Representation

## Introduction

This repository contains the materials for the course entitled “CS 2150: Program and Data Representation” in the Computer Science Department at the University of Virginia. It contains all of the slides, labs, exams, etc., used throughout the course. The course description is below. The github repository for this course is at https://github.com/uva-cs/pdr. It can be viewed online at http://uva-cs.github.io/pdr/.

Students currently in the course should view the uva/index.html (md) file in the cloned repository (i.e., don’t try to view it on github.com); current students may also want to view the daily announcements. Note that many of the course materials are modified right before they are needed – for example, this repository will be updated right before the semester starts.

Students who were previously in the course may want to view the current version, or you can view the version from your semester. All semester versions are tagged with an end-of-semester tag of the form “year-semester”. For example, the spring 2014 semester was tagged as 2014-spring. To obtain a specific tag, you can enter git checkout tags/2014-spring in an already cloned repository.

The primary authors of this repository are Mark Floryan (mrf8t@cs.virginia.edu), Rich Nguyen (nn4pj@virginia.edu), and Aaron Bloomfield (aaron@virginia.edu). Many students and faculty have worked on this course material over the years.

## Repository Contents

Note that the links below will not work correctly if you are viewing this online at github.com – you will need to clone (download) the repository first

book (md): the beginnings of a textbook to be used for this course. It is written using LaTeX.
docs (md): a series of useful documents that are not labs or tutorials.
uva (md): the materials that are specific to CS 2150 as taught at the University of Virginia, such as daily announcements, due dates, etc.
exams (md): past exams for the course; there are two midterms and a final for each semester.
ibcm (md): the files necessary for the IBCM module on machine language, which is taught about two thirds of the way into the course.
labs (md): the labs are the main assignments in the course, and each lab is split into pre-lab, in-lab, and post-lab parts. There are 11 full labs, with a partial 12th lab that is an optional component of the course. The labs are written using markdown, and the rendered HTML version of each lab is also committed to this repository.
slides (md): Contains the slides used in the course. The slides use reveal.js, an HTML presentation framework.
tutorials (md): the tutorials that are used as part of the lab assignments, these are primarily Linux tutorials.
utils (md): various utilities for this repository
Contributing to this Repository

Updates to the repository are restricted to approved individuals only, to prevent anybody from messing with the slides right before a lecture. However, others can still contribute to this repository – to do so, take the following steps:

Create a github account, if you do not have one
Fork this repository: you can click on the “Fork” link in the upper right, or just click here
Clone your forked repository on to your local machine
Make any changes you want to your forked version
Run make - note that you will need pandoc, astyle, and source-highlight installed
Commit and push your changes back to your forked repository
Create a pull request, following the instructions here
At that point, I will receive a notice that a change has been submitted, and I’ll look at it and hopefully accept it into the main repository.

When you want to bring in the updates from the main pdr github repository into your forked repository, you will need to follow the instructions here.

## Course Description

This course is a second-year course for computer science majors. It is the primary data structures course in the University of Virginia’s computer science curriculum. Unlike many other data structure courses at other institutions, it is intended as the third course in sequence, meaning that students are expected to have taken two semesters of Java (or equivalent, although some of the examples are specifically from Java). The course focuses on how programs and data are represented from the high level down to the low level. For programs, we examine (from high to low): abstract data types, Java code, C++ code, C code, assembly (x86) code, and a customized machine language. For data, we examine (also from high to low): abstract data types, objects, primitive types, and how numbers are encoded (both floats (IEEE 754) and integers (two’s complement)). About two-thirds of this course is programming using C++. The remainder of this course uses other languages, including (in decreasing order): x86 assembly, IBCM (a machine language), C, Objective C, and shell scripting.

The ABET course objects are as follows:

Understand program representation from the high-level programming language perspective down to the underlying machine level representation, including: number representation, operations, conditionals, and control structures
Be able to implement basic and advanced abstract data types in C++ including: linked lists, stacks, queues, hash tables, trees, and graphs
Be able to evaluate asymptotic time and space complexity analysis of programs and data structure implementations using Big-O, Big-Omega, and Big-Theta notation and assess the suitability of a data structure for a particular problem
Understand the basic program execution model and the underlying computer hardware and software (fetch-execute cycle, memory hierarchy, operating system, compiler)
Be able to implement basic program control and data structures in an assembly language (loops, conditionals, subroutines and parameter passing modes, arrays)
Markdown

The majority of the content in this repository was created using Markdown. Unfortunately, the only standardized Markdown is very old (2004), and has limited support for many HTML features, such as tables. A simple conversion script in a Makefile is in the utils (md) directory, which uses pandoc. Assuming pandoc is installed, run make markdown in the root repo directory to re-create all the .html files from their associated .md files.

For all the Markdown files in this repository, both the original (.md) file and the HTML version (.html) are added to the repository, so that people who do not have Markdown installed can still view the contents of this repository.

Note that Github supports an enhanced version of Markdown, called Github Flavored Markdown, or GFM. This mostly pertains to this README file. In an effort to ensure compatibility with other Markdown programs (such as the one described here and what reveal.js uses), GFM specific features are generally avoided. One example is the use of anchors in this document – the HTML tags are included instead of using GFM’s version.

## Source code

All source code is formatted via astyle and then highlighted via source-highlight. Both the original file (foo.cpp) and the highlighted version (foo.cpp.html) are included in the repository. All links to source code will like to the .html, with a “(src)” after it to link to the original source code. Utility scripts are provided to convert all the files in the utils (md) directory. make format and make highlight can also be run to invoke the scripts.

## License

The material in this repository is released under a Creative Commons Attribution-ShareAlike 4.0 International License (CC BY-SA).

Copyright (c) 2017-2018 by Mark Floryan Copyright (c) 2013-2017 by Aaron Bloomfield.

Some parts of this repository are taken, with permission, from other sources. The full details are in the License (md) file. In particular, some parts of this repository that were obtained elsewhere can not be used for commercial purposes.
