<?php

/* based on php version of the geoip library written in may 2002
   by jim winstead <jimw@apache.org> */

/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 2; tab-width: 2 -*- */
/* GeoIP.c
 *
 * Copyright (C) 2002 MaxMind
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

$GEOIP_COUNTRY_CODES = array(
"", "AP", "EU", "AD", "AE", "AF", "AG", "AI", "AL", "AM", "AN", "AO", "AQ",
"AR", "AS", "AT", "AU", "AW", "AZ", "BA", "BB", "BD", "BE", "BF", "BG", "BH",
"BI", "BJ", "BM", "BN", "BO", "BR", "BS", "BT", "BV", "BW", "BY", "BZ", "CA",
"CC", "CD", "CF", "CG", "CH", "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CU",
"CV", "CX", "CY", "CZ", "DE", "DJ", "DK", "DM", "DO", "DZ", "EC", "EE", "EG",
"EH", "ER", "ES", "ET", "FI", "FJ", "FK", "FM", "FO", "FR", "FX", "GA", "GB",
"GD", "GE", "GF", "GH", "GI", "GL", "GM", "GN", "GP", "GQ", "GR", "GS", "GT",
"GU", "GW", "GY", "HK", "HM", "HN", "HR", "HT", "HU", "ID", "IE", "IL", "IN",
"IO", "IQ", "IR", "IS", "IT", "JM", "JO", "JP", "KE", "KG", "KH", "KI", "KM",
"KN", "KP", "KR", "KW", "KY", "KZ", "LA", "LB", "LC", "LI", "LK", "LR", "LS",
"LT", "LU", "LV", "LY", "MA", "MC", "MD", "MG", "MH", "MK", "ML", "MM", "MN",
"MO", "MP", "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ", "NA",
"NC", "NE", "NF", "NG", "NI", "NL", "NO", "NP", "NR", "NU", "NZ", "OM", "PA",
"PE", "PF", "PG", "PH", "PK", "PL", "PM", "PN", "PR", "PS", "PT", "PW", "PY",
"QA", "RE", "RO", "RU", "RW", "SA", "SB", "SC", "SD", "SE", "SG", "SH", "SI",
"SJ", "SK", "SL", "SM", "SN", "SO", "SR", "ST", "SV", "SY", "SZ", "TC", "TD",
"TF", "TG", "TH", "TJ", "TK", "TM", "TN", "TO", "TP", "TR", "TT", "TV", "TW",
"TZ", "UA", "UG", "UM", "US", "UY", "UZ", "VA", "VC", "VE", "VG", "VI", "VN",
"VU", "WF", "WS", "YE", "YT", "YU", "ZA", "ZM", "ZR", "ZW"
);

$GEOIP_COUNTRY_CODES3 = array (
"","AP","EU","AND","ARE","AFG","ATG","AIA","ALB","ARM","ANT","AGO","AQ","ARG",
"ASM","AUT","AUS","ABW","AZE","BIH","BRB","BGD","BEL","BFA","BGR","BHR","BDI",
"BEN","BMU","BRN","BOL","BRA","BHS","BTN","BV","BWA","BLR","BLZ","CAN","CC",
"COD","CAF","COG","CHE","CIV","COK","CHL","CMR","CHN","COL","CRI","CUB","CPV",
"CX","CYP","CZE","DEU","DJI","DNK","DMA","DOM","DZA","ECU","EST","EGY","ESH",
"ERI","ESP","ETH","FIN","FJI","FLK","FSM","FRO","FRA","FX","GAB","GBR","GRD",
"GEO","GUF","GHA","GIB","GRL","GMB","GIN","GLP","GNQ","GRC","GS","GTM","GUM",
"GNB","GUY","HKG","HM","HND","HRV","HTI","HUN","IDN","IRL","ISR","IND","IO",
"IRQ","IRN","ISL","ITA","JAM","JOR","JPN","KEN","KGZ","KHM","KIR","COM","KNA",
"PRK","KOR","KWT","CYM","KAZ","LAO","LBN","LCA","LIE","LKA","LBR","LSO","LTU",
"LUX","LVA","LBY","MAR","MCO","MDA","MDG","MHL","MKD","MLI","MMR","MNG","MAC",
"MNP","MTQ","MRT","MSR","MLT","MUS","MDV","MWI","MEX","MYS","MOZ","NAM","NCL",
"NER","NFK","NGA","NIC","NLD","NOR","NPL","NRU","NIU","NZL","OMN","PAN","PER",
"PYF","PNG","PHL","PAK","POL","SPM","PCN","PRI","PSE","PRT","PLW","PRY","QAT",
"REU","ROU","RUS","RWA","SAU","SLB","SYC","SDN","SWE","SGP","SHN","SVN","SJM",
"SVK","SLE","SMR","SEN","SOM","SUR","STP","SLV","SYR","SWZ","TCA","TCD","TF",
"TGO","THA","TJK","TKL","TLS","TKM","TUN","TON","TUR","TTO","TUV","TWN","TZA",
"UKR","UGA","UM","USA","URY","UZB","VAT","VCT","VEN","VGB","VIR","VNM","VUT",
"WLF","WSM","YEM","YT","YUG","ZAF","ZMB","ZR","ZWE","A1","A2","O1");

$GEOIP_COUNTRY_NAMES = array(
"", "Asia/Pacific Region", "Europe", "Andorra", "United Arab Emirates",
"Afghanistan", "Antigua and Barbuda", "Anguilla", "Albania", "Armenia",
"Netherlands Antilles", "Angola", "Antarctica", "Argentina", "American Samoa",
"Austria", "Australia", "Aruba", "Azerbaijan", "Bosnia and Herzegovina",
"Barbados", "Bangladesh", "Belgium", "Burkina Faso", "Bulgaria", "Bahrain",
"Burundi", "Benin", "Bermuda", "Brunei Darussalam", "Bolivia", "Brazil",
"Bahamas", "Bhutan", "Bouvet Island", "Botswana", "Belarus", "Belize",
"Canada", "Cocos (Keeling) Islands", "Congo, The Democratic Republic of the",
"Central African Republic", "Congo", "Switzerland", "Cote D'Ivoire", "Cook
Islands", "Chile", "Cameroon", "China", "Colombia", "Costa Rica", "Cuba", "Cape
Verde", "Christmas Island", "Cyprus", "Czech Republic", "Germany", "Djibouti",
"Denmark", "Dominica", "Dominican Republic", "Algeria", "Ecuador", "Estonia",
"Egypt", "Western Sahara", "Eritrea", "Spain", "Ethiopia", "Finland", "Fiji",
"Falkland Islands (Malvinas)", "Micronesia, Federated States of", "Faroe
Islands", "France", "France, Metropolitan", "Gabon", "United Kingdom",
"Grenada", "Georgia", "French Guiana", "Ghana", "Gibraltar", "Greenland",
"Gambia", "Guinea", "Guadeloupe", "Equatorial Guinea", "Greece", "South Georgia
and the South Sandwich Islands", "Guatemala", "Guam", "Guinea-Bissau",
"Guyana", "Hong Kong", "Heard Island and McDonald Islands", "Honduras",
"Croatia", "Haiti", "Hungary", "Indonesia", "Ireland", "Israel", "India",
"British Indian Ocean Territory", "Iraq", "Iran, Islamic Republic of",
"Iceland", "Italy", "Jamaica", "Jordan", "Japan", "Kenya", "Kyrgyzstan",
"Cambodia", "Kiribati", "Comoros", "Saint Kitts and Nevis", "Korea, Democratic
People's Republic of", "Korea, Republic of", "Kuwait", "Cayman Islands",
"Kazakstan", "Lao People's Democratic Republic", "Lebanon", "Saint Lucia",
"Liechtenstein", "Sri Lanka", "Liberia", "Lesotho", "Lithuania", "Luxembourg",
"Latvia", "Libyan Arab Jamahiriya", "Morocco", "Monaco", "Moldova, Republic
of", "Madagascar", "Marshall Islands", "Macedonia, the Former Yugoslav Republic
of", "Mali", "Myanmar", "Mongolia", "Macau", "Northern Mariana Islands",
"Martinique", "Mauritania", "Montserrat", "Malta", "Mauritius", "Maldives",
"Malawi", "Mexico", "Malaysia", "Mozambique", "Namibia", "New Caledonia",
"Niger", "Norfolk Island", "Nigeria", "Nicaragua", "Netherlands", "Norway",
"Nepal", "Nauru", "Niue", "New Zealand", "Oman", "Panama", "Peru", "French
Polynesia", "Papua New Guinea", "Philippines", "Pakistan", "Poland", "Saint
Pierre and Miquelon", "Pitcairn", "Puerto Rico", "Palestinian Territory,
Occupied", "Portugal", "Palau", "Paraguay", "Qatar", "Reunion", "Romania",
"Russian Federation", "Rwanda", "Saudi Arabia", "Solomon Islands",
"Seychelles", "Sudan", "Sweden", "Singapore", "Saint Helena", "Slovenia",
"Svalbard and Jan Mayen", "Slovakia", "Sierra Leone", "San Marino", "Senegal",
"Somalia", "Suriname", "Sao Tome and Principe", "El Salvador", "Syrian Arab
Republic", "Swaziland", "Turks and Caicos Islands", "Chad", "French Southern
Territories", "Togo", "Thailand", "Tajikistan", "Tokelau", "Turkmenistan",
"Tunisia", "Tonga", "East Timor", "Turkey", "Trinidad and Tobago", "Tuvalu",
"Taiwan, Province of China", "Tanzania, United Republic of", "Ukraine",
"Uganda", "United States Minor Outlying Islands", "United States", "Uruguay",
"Uzbekistan", "Holy See (Vatican City State)", "Saint Vincent and the
Grenadines", "Venezuela", "Virgin Islands, British", "Virgin Islands, U.S.",
"Vietnam", "Vanuatu", "Wallis and Futuna", "Samoa", "Yemen", "Mayotte",
"Yugoslavia", "South Africa", "Zambia", "Zaire", "Zimbabwe"
);

define("GEOIP_COUNTRY_BEGIN", 16776960);
define("GEOIP_STATE_BEGIN", 16700000);
define("GEOIP_STANDARD", 0);
define("GEOIP_MEMORY_CACHE", 1);
define("STRUCTURE_INFO_MAX_SIZE",20);
define("DATABASE_INFO_MAX_SIZE",100);
define("GEOIP_COUNTRY_EDITION",106);
define("GEOIP_REGION_EDITION",112);
define("GEOIP_CITY_EDITION",111);
define("RECORD_LENGTH",3);

class GeoIP {
  var $flags;
  var $filehandle;
  var $memory_buffer;
  var $databaseType;
  var $databaseSegments;
}

function _setup_segments($gi){
  $filepos = ftell($gi->filehandle);
  $gi->databaseType = GEOIP_COUNTRY_EDITION;
  fseek($gi->filehandle, -3, SEEK_END);
  for ($i = 0; $i < STRUCTURE_INFO_MAX_SIZE; $i++) {
    $delim = fread($gi->filehandle,3);
    if ($delim == (chr(255).chr(255).chr(255))){
      $gi->databaseType = ord(fread($gi->filehandle,1));
      if ($gi->databaseType == GEOIP_REGION_EDITION){
        $gi->databaseSegments = GEOIP_STATE_BEGIN;
      } else if ($gi->databaseType == GEOIP_CITY_EDITION){
        $gi->databaseSegments = 0;
        $buf = fread($gi->filehandle,RECORD_LENGTH);
        for ($j = 0;$j < RECORD_LENGTH;$j++){
          $gi->databaseSegments += (ord($buf[$j]) << ($j * 8));
        }
      }
      break;
    } else {
      fseek($gi->filehandle, -4, SEEK_CUR);
    }
  }
  if ($gi->databaseType == GEOIP_COUNTRY_EDITION){
    $gi->databaseSegments = GEOIP_COUNTRY_BEGIN;
  }
  fseek($gi->filehandle,$filepos,SEEK_SET);
  return $gi;
}

function geoip_open($filename, $flags) {
  $gi = new GeoIP;
  $gi->flags = $flags;

  $gi->filehandle = fopen($filename,"rb");

  if ($gi->flags & GEOIP_MEMORY_CACHE) {
    $s_array = fstat($gi->filehandle);
    $gi->memory_buffer = fread($gi->filehandle, $s_array[size]);
  }
  $gi = _setup_segments($gi);
  return $gi;
}

function geoip_close($gi) {
  return fclose($gi->filehandle);
}

function geoip_country_id_by_name($gi, $name) {
  $addr = gethostbyname($name);
  if (!$addr || $addr == $name) {
    return false;
  }
  return geoip_country_id_by_addr($gi, $addr);
}

function geoip_country_code_by_name($gi, $name) {
  $country_id = geoip_country_id_by_name($gi,$name);
  if ($country_id !== false) {
    return $GLOBALS['GEOIP_COUNTRY_CODES'][$country_id];
  }
  return false;
}

function geoip_country_name_by_name($gi, $name) {
  $country_id = geoip_country_id_by_name($gi,$name);
  if ($country_id !== false) {
    return $GLOBALS['GEOIP_COUNTRY_NAMES'][$country_id];
  }
  return false;
}

function geoip_country_id_by_addr($gi, $addr) {
  $ipnum = ip2long($addr);
  return _geoip_seek_country($gi, $ipnum) - GEOIP_COUNTRY_BEGIN;
}

function geoip_country_code_by_addr($gi, $addr) {
  $country_id = geoip_country_id_by_addr($gi,$addr);
  if ($country_id !== false) {
    return $GLOBALS['GEOIP_COUNTRY_CODES'][$country_id];
  }
  return false;
}

function geoip_country_name_by_addr($gi, $addr) {
  $country_id = geoip_country_id_by_addr($gi,$addr);
  if ($country_id !== false) {
    return $GLOBALS['GEOIP_COUNTRY_NAMES'][$country_id];
  }
  return false;
}

function _geoip_seek_country($gi, $ipnum) {
  $offset = 0;
  for ($depth = 31; $depth >= 0; --$depth) {
    if ($gi->flags & GEOIP_MEMORY_CACHE) {
      $buf = substr($gi->memory_buffer,6 * $offset, 6);
    } else {
      fseek($gi->filehandle, 6 * $offset, SEEK_SET) == 0
        or die("fseek failed");
      $buf = fread($gi->filehandle,6);
    }
    $x = array(0,0);
    for ($i = 0; $i < 2; ++$i) {
      for ($j = 0; $j < 3; ++$j) {
        $x[$i] += ord($buf[($i*3)+$j]) << ($j * 8);
      }
    }
    if ($ipnum & (1 << $depth)) {
      if ($x[1] >= $gi->databaseSegments) {
        return $x[1];
      }
      $offset = $x[1];
    }
    else {
      if ($x[0] >= $gi->databaseSegments) {
        return $x[0];
      }
      $offset = $x[0];
    }
  }

  trigger_error("error traversing database - perhaps it is corrupt?", E_USER_ERROR);
  return false;
}

function _get_region($gi,$ipnum){
  $seek_region = _geoip_seek_country($gi,$ipnum) - GEOIP_STATE_BEGIN;
  if ($seek_region >= 1000){
    $country_code = "US";
    $region = chr(($seek_region - 1000)/26 + 65) . chr(($seek_region - 1000)%26 + 65);
  } else {
    $country_code = $GLOBALS['GEOIP_COUNTRY_CODES'][$seek_region];
    $region = "";
  }
  return array ($country_code,$region);
}

function geoip_region_by_addr ($gi,$addr) {
  if ($addr == NULL) {
    return 0;
  }
  $ipnum = ip2long($addr);
  return _get_region($gi, $ipnum);
}

?>
