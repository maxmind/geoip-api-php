<?php

class CountryTest extends \PHPUnit_Framework_TestCase
{

    public function testCountry()
    {
        $gi = geoip_open("tests/data/GeoIP.dat", GEOIP_STANDARD);

        $this->assertEquals(
            'US',
            geoip_country_code_by_addr($gi, '64.17.254.216')
        );
        $this->assertEquals(
            'United States',
            geoip_country_name_by_addr($gi, '64.17.254.216')
        );
    }

    public function testV6()
    {
        $gi = geoip_open("tests/data/GeoIPv6.dat", GEOIP_STANDARD);

        $this->assertEquals(
            'JP',
            geoip_country_code_by_addr_v6($gi, '2001:200::')
        );
    }
}
