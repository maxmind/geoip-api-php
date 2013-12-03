<?php

if (!$loader = @include __DIR__ . '/../vendor/autoload.php') {
    die('Project dependencies missing');
}
