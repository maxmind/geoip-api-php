<?php

class NetspeedcellTest extends \PHPUnit_Framework_TestCase
{
    public function testNetspeedcell()
    {
        $gi = geoip_open("tests/data/GeoIPNetSpeedCell.dat", GEOIP_STANDARD);

        $this->assertEquals(
            'Dialup',
            geoip_org_by_addr($gi, "2.125.160.1")
        );
    }
}
