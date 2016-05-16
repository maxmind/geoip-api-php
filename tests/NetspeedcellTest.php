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

    public function testNetspeedcellWithSharedMemory()
    {
        // HHVM doesn't support shared memory
        if (defined('HHVM_VERSION')) {
            $this->markTestSkipped();
        }
        geoip_load_shared_mem("tests/data/GeoIPNetSpeedCell.dat");

        $gi = geoip_open("tests/data/GeoIPNetSpeedCell.dat", GEOIP_SHARED_MEMORY);

        $this->assertEquals(
            'Dialup',
            geoip_name_by_addr($gi, "2.125.160.1")
        );
    }
}
