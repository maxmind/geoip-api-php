<?php

class DomainTest extends \PHPUnit_Framework_TestCase
{

    public function testDomain()
    {
        $gi = geoip_open("tests/data/GeoIPDomain.dat", GEOIP_STANDARD);

        $this->assertEquals(
            'shoesfin.NET',
            geoip_org_by_addr($gi, "67.43.156.0")
        );
    }
}
