<?php

class OrgTest extends \PHPUnit_Framework_TestCase
{
    public function testOrg()
    {
        $gi = geoip_open("tests/data/GeoIPOrg.dat", GEOIP_STANDARD);

        $this->assertEquals(
            'AT&T Worldnet Services',
            geoip_org_by_addr($gi, "12.87.118.0")
        );
    }
}
