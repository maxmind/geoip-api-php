#!/usr/bin/php -q
<?php

// This code demonstrates how to lookup the country by IP Address
// Note this code will only work with GeoIP/GeoLite Country
// It will not work with GeoIP/GeoLite City
// For an example of how to query GeoIP/GeoLite City, see sample_city.php

include("geoip.inc");

$gi = geoip_open("/usr/local/share/GeoIP/GeoIP.dat",GEOIP_STANDARD);

echo geoip_country_code_by_addr($gi, "24.24.24.24") . "\t" .
     geoip_country_name_by_addr($gi, "24.24.24.24") . "\n";
echo geoip_country_code_by_addr($gi, "80.24.24.24") . "\t" .
     geoip_country_name_by_addr($gi, "80.24.24.24") . "\n";

geoip_close($gi);

?>
