#!/usr/bin/perl
use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

my $grass = ".";
my $tree = "o";
my $house = "x";

print "$y$grass$tree$house \n";
for (my $i = 0; $i < $y; $i++)
{
	for (my $j = 0; $j < $x; $j++)
	{
		if (int(rand($y) * 2) < $density)
		{
			print $tree;
		}
		else
		{
			print $grass;
		}
	}
	print "\n";
}
