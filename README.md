# MaxMind GeoIP PHP API #

## Requirements ##

This module has no external dependencies. You only need a MaxMind GeoIP
database. To download a free GeoIP Standard Country database, please see
our [GeoLite page](http://dev.maxmind.com/geoip/geolite).

## Installing with Composer ##

### Define Your Dependencies ###

We recommend installing this package with [Composer](http://getcomposer.org/).
To do this, add ```geoip/geoip``` to your ```composer.json``` file.

```json
{
    "require": {
        "geoip/geoip": "~1.14"
    }
}
```

### Install Composer ###

Run in your project root:

```
curl -s http://getcomposer.org/installer | php
```

### Install Dependencies ###

Run in your project root:

```
php composer.phar install
```

### Require Autoloader ###

You can autoload all dependencies by adding this to your code:
```
require 'vendor/autoload.php';
```

## Installing without Composer ##

Place the 'geoip.inc' file in the `include_path` as specified in your
`php.ini` file or place it in the same directory as your PHP scripts.

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

## Support ##

For help with this API or our databases, please see [our support page]
(http://www.maxmind.com/en/support).

## Copyright and License ##

This software is Copyright (c) 2013 by MaxMind, Inc.

This is free software, licensed under the GNU Lesser General Public License
version 2.1 or later.

## Thanks ##

Thanks to Jim Winstead.
