#!/usr/bin/perl -s

# Usage: Usage: perl picc18_dep.pl -dep_file=*.d -obj_file=*.o

# -----------------------------------------------------------------------------
# Standard exit process

sub ShowErrorAndExit
{
  print "Execution of picc18_dep.pl has aborted:\n";
  die $_[0], "\n";
}

printf("%s %s: \\\n", $obj_file, $dep_file);
while (defined($_ = <STDIN>))
{ 
  print " ";
  s/\n/ \\/;
  print $_;
  print "\n";
}
print "\n";

