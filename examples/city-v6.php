#!/usr/bin/php -q
<?php

// This code demonstrates how to lookup the country, region, city,
// postal code, latitude, and longitude by IP Address.
// It is designed to work with GeoIP/GeoLite City

// Note that you must download the New Format of GeoIP City (GEO-133).
// The old format (GEO-132) will not work.

include '../src/geoipcity.inc';
include '../src/geoipregionvars.php';

// uncomment for Shared Memory support
// geoip_load_shared_mem("/usr/local/share/GeoIP/GeoIPCity.dat");
// $gi = geoip_open("/usr/local/share/GeoIP/GeoIPCity.dat",GEOIP_SHARED_MEMORY);

$gi = geoip_open('/usr/local/share/GeoIP/GeoLiteCityv6.dat', GEOIP_STANDARD);

$record = GeoIP_record_by_addr_v6($gi, '::24.24.24.24');
echo $record->country_code.' '.$record->country_code3.' '.$record->country_name."\n";
echo $record->region.' '.$GEOIP_REGION_NAME[$record->country_code][$record->region]."\n";
echo $record->city."\n";
echo $record->postal_code."\n";
echo $record->latitude."\n";
echo $record->longitude."\n";
echo $record->metro_code."\n";
echo $record->area_code."\n";
echo $record->continent_code."\n";

geoip_close($gi);
