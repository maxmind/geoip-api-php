#!/usr/bin/php -q
<?php

// This code demonstrates how to lookup the country and region by IP Address
// It is designed to work with GeoIP Organization or GeoIP ISP available from MaxMind

include("geoip.inc");

$gi = geoip_open("/usr/local/share/GeoIP/GeoIPOrg.dat",GEOIP_STANDARD);

$org = geoip_org_by_addr($gi,"80.24.24.24");
print "80.24.24.24 belongs to " . $org . "\n";

geoip_close($gi);

?>
