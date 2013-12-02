#!/usr/bin/php -q
<?php

function download_and_open($url)
{
	$file = basename($url);
	if ( !file_exists( sprintf('%s/%s', __DIR__, $file) ) ) {
		$ch = curl_init();
		$timeout = 5;
		curl_setopt($ch, CURLOPT_URL, $url);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);
		$data = curl_exec($ch);
		curl_close($ch);
		file_put_contents( $file, $data);
	}
	return file($file);
}

$fips10_4 = download_and_open('https://raw.github.com/maxmind/geoip-api-c/master/regioncode/fips10_4.txt');
array_shift($fips10_4);
$iso3166_2 = download_and_open('https://raw.github.com/maxmind/geoip-api-c/master/regioncode/iso3166_2.txt');
array_shift($iso3166_2);
$countries = array_merge($fips10_4, $iso3166_2);

$array = array();
foreach ($countries as $line) {
	$datas = explode(',', $line);
	$array[$datas[0]][trim(preg_replace('/"/im', '', $datas[2]))] = sprintf("%s", $datas[1]);
}
$array = array_map('array_flip', $array);

date_default_timezone_set("UTC");
$output .= "<?php\n";
$output .= sprintf("# Copyright %s MaxMind, Inc. All Rights Reserved\n", date('Y'));
$output .= 'Global $GEOIP_REGION_NAME = ' . var_export($array, true);

file_put_contents( __DIR__ . '/../src/geoipregionvars.php', $output);