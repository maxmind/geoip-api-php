#!/usr/bin/php -q
<?php

// This code demonstrates how to lookup the country, region, city,
// postal code, latitude, and longitude by IP Address.
// It is designed to work with GeoIP City Edition available from MaxMind

include("geoipcity.inc");

$gi = geoip_open("/usr/local/share/GeoIP/GeoIPCity.dat",GEOIP_STANDARD);

$record = geoip_record_by_addr($gi,"67.242.4.86");
print $record->country_code . " " . $record->country_code3 . " " . $record->country_name . "\n";
print $record->region . "\n";
print $record->city . "\n";
print $record->postal_code . "\n";
print $record->latitude . "\n";
print $record->longitude . "\n";
print $record->dma_code . "\n";
print $record->area_code . "\n";

geoip_close($gi);

?>
