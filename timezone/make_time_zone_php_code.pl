#!/usr/bin/perl

use strict;
use warnings;

use HTTP::Tiny;
use Text::CSV_XS;

my $old_country = q{};
my $old_region = q{};

my $response = HTTP::Tiny->new->get(
    'http://dev.maxmind.com/static/csv/codes/time_zone.csv');

die "Failed to download CSV!\n" unless $response->{success};

print <<'EOF';
<?php

/**
 * Get time zone
 * @param string $country
 * @param string $region
 * @return string If the timezone is not found, returns NULL
 */
function get_time_zone($country, $region)
{
    $timezone = null;
    switch ($country) {
EOF

my $csv = Text::CSV_XS->new ({ binary => 1});

my @timezones = split /\n/, $response->{content};
shift @timezones;

for my $line (@timezones) {
    $csv->parse($line) or die $csv->error_diag();
    my ( $country, $region, $timezone ) = $csv->fields;

    if ( $country ne $old_country ) {
        if ( $old_region ne q{} ) {
            print "        }\n";
            print "        break;\n";
        }
        print '        case "' . $country . q(") . ":\n";
        if ( $region ne q{} ) {
            print "            switch (\$region) {\n";
        }
    }
    if ( $region ne q{} ) {
        print '                case "' . $region . q(") . ":\n        ";
    }
    print '            $timezone = "' . $timezone . q(") . ";\n";
    if ( $region ne q{} ) {
        print "                    break;\n";
    }
    else {
        print "            break;\n";
    }
    $old_country = $country;
    $old_region  = $region;
}
print "    }\n";
print "    return \$timezone;\n";

print "}\n";

