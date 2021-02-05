# MaxMind GeoIP Legacy PHP API #

## End of Life ##

MaxMind will be retiring the GeoIP Legacy databases at the end of May
2022. Until then, this library will only receive critical security and bug
fixes. Support for this library will end completely with the last release of
the legacy GeoIP databases.

We recommend that you upgrade to our GeoIP2 databases. You can read these
from PHP with [our GeoIP2 PHP API](https://github.com/maxmind/GeoIP2-php).

See [our blog post](https://blog.maxmind.com/2020/06/01/retirement-of-geoip-legacy-downloadable-databases-in-may-2022/)
for more information.

## Requirements ##

This module has no external dependencies. You only need a MaxMind GeoIP
database.

## Install via Composer ##

We recommend installing this package with [Composer](http://getcomposer.org/).

### Download Composer ###

To download Composer, run in the root directory of your project:

```bash
curl -sS https://getcomposer.org/installer | php
```

You should now have the file `composer.phar` in your project directory.

### Install Dependencies ###

Run in your project root:

```
php composer.phar require geoip/geoip:~1.16
```

You should now have the files `composer.json` and `composer.lock` as well as
the directory `vendor` in your project directory. If you use a version control
system, `composer.json` should be added to it.

### Require Autoloader ###

After installing the dependencies, you need to require the Composer autoloader
from your code:

```php
require 'vendor/autoload.php';
```

## Install without Composer ##

Place the 'geoip.inc' file in the `include_path` as specified in your
`php.ini` file or place it in the same directory as your PHP scripts.


## IP Geolocation Usage ##

IP geolocation is inherently imprecise. Locations are often near the center of
the population. Any location provided by a GeoIP database should not be used to
identify a particular address or household.

## Usage ##

Gets country name by hostname :

```php
<?php

require 'vendor/autoload.php';

$gi = geoip_open("/usr/local/share/GeoIP/GeoIP.dat",GEOIP_STANDARD);

echo geoip_country_code_by_addr($gi, "24.24.24.24") . "\t" .
     geoip_country_name_by_addr($gi, "24.24.24.24") . "\n";
echo geoip_country_code_by_addr($gi, "80.24.24.24") . "\t" .
     geoip_country_name_by_addr($gi, "80.24.24.24") . "\n";

geoip_close($gi);
```

## Memory Caching ##

To enable memory caching, pass `GEOIP_SHARED_MEMORY` or `GEOIP_MEMORY_CACHE`
as the second argument of `geoip_open`.

`GEOIP_SHARED_MEMORY` requires php >= 4.0.4 compiled with `--enable-shmop`
configure time.  See (http://us2.php.net/manual/en/ref.shmop.php).
In addition, you should call `geoip_load_shared_mem` before calling
`geoip_open`.  See `sample_city.php` for an example of shared memory caching.

## Requirements  ##

This code is tested on PHP 5.4 and greater. Older versions of PHP may work.

## Support ##

For help with this API or our databases, please see [our support page](http://www.maxmind.com/en/support).

## Copyright and License ##

This software is Copyright (c) 2016 by MaxMind, Inc.

This is free software, licensed under the GNU Lesser General Public License
version 2.1 or later.

## Thanks ##

Thanks to Jim Winstead.
