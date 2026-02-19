#!/bin/bash

rm -f /vagrant/unit_tests/seq.txt
./push_swap 3 8 0 5 10 2 7 1 9 4 6 >> /vagrant/unit_tests/seq.txt

