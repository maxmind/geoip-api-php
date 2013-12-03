<?php

class RegionTest extends \PHPUnit_Framework_TestCase
{
    public function testRegion()
    {
        $gi = geoip_open("tests/data/GeoIPRegion.dat", GEOIP_STANDARD);

        list($countryCode, $region) = geoip_region_by_addr(
            $gi,
            '64.17.254.223'
        );

        $this->assertEquals('CA', $region);
        $this->assertEquals('US', $countryCode);

        global $GEOIP_REGION_NAME;
        $this->assertEquals(
            'California',
            $GEOIP_REGION_NAME[$countryCode][$region]
        );
    }
}
