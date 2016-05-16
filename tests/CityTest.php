<?php

class CityTest extends \PHPUnit_Framework_TestCase
{

    public function testCity()
    {
        global $GEOIP_REGION_NAME;

        $gi = geoip_open("tests/data/GeoIPCity.dat", GEOIP_STANDARD);

        $record = geoip_record_by_addr($gi, "64.17.254.216");

        $this->assertEquals(310, $record->area_code);
        $this->assertEquals('El Segundo', $record->city);
        $this->assertEquals('US', $record->country_code);
        $this->assertEquals('USA', $record->country_code3);
        $this->assertEquals('United States', $record->country_name);
        $this->assertEquals(803, $record->dma_code);
        $this->assertEquals(33.91, $record->latitude, '', 0.01);
        $this->assertEquals(-118.40, $record->longitude, '', 0.01);
        $this->assertEquals(803, $record->metro_code);
        $this->assertEquals('90245', $record->postal_code);
        $this->assertEquals('CA', $record->region);
        $this->assertEquals(
            'California',
            $GEOIP_REGION_NAME[$record->country_code][$record->region]
        );
        $this->assertEquals(
            'America/Los_Angeles',
            get_time_zone($record->country_code, $record->region)
        );

        $this->assertEquals(
            'US',
            geoip_country_code_by_addr($gi, "64.17.254.216")
        );
    }

    public function testCityWithSharedMemory()
    {
        // HHVM doesn't support shared memory
        if (defined('HHVM_VERSION')) {
            $this->markTestSkipped();
        }
        geoip_load_shared_mem("tests/data/GeoIPCity.dat");

        $gi = geoip_open("tests/data/GeoIPCity.dat", GEOIP_SHARED_MEMORY);
        $record = geoip_record_by_addr($gi, "222.230.136.0");

        $this->assertEquals('Setagaya', $record->city);
    }
}
