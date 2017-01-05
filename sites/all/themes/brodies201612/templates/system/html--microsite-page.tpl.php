<!doctype html>
<!--[if lt IE 7]> <html class="ie6 oldie"> <![endif]-->
<!--[if IE 7]>    <html class="ie7 oldie"> <![endif]-->
<!--[if IE 8]>    <html class="ie8 oldie"> <![endif]-->
<!--[if gt IE 8]><!-->
<html class="">
    <!--<![endif]-->
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <?php print $head ?>
        <title><?php print $head_title ?></title>
        <?php print $styles ?>
<?php print $scripts ?>   
        <link href="/sites/all/themes/brodies201612/microsites/css/boilerplate.css" rel="stylesheet" type="text/css">
        <link href="/sites/all/themes/brodies201612/microsites/css/microsites.css" rel="stylesheet" type="text/css">
        <!--[if lt IE 9]>
        <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
        <![endif]-->
        <script src="/sites/all/themes/brodies201612/microsites/js/respond.min.js"></script>
        <script type="text/javascript">
          function MM_jumpMenu(targ, selObj, restore) { //v3.0
              eval(targ + ".location='" + selObj.options[selObj.selectedIndex].value + "'");
              if (restore)
                  selObj.selectedIndex = 0;
          }
        </script>
    </head>
    <body>
         <?php print $page; ?>

        <script type="text/javascript" src="/sites/all/themes/brodies201612/microsites/js/map-locations-dist.js"></script>
    </body>
</html>
