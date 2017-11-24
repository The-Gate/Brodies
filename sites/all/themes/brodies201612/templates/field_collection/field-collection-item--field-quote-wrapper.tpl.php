<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<?php

$defaultBodyColour = "#54565b";
$quotecolour = (!(empty($content['field_quote_text_colour'][0]['#markup']))) ? $content['field_quote_text_colour'][0]['#markup'] : $defaultBodyColour;
$quoteTextColourStyle = (!($quotecolour == $defaultBodyColour)) ? ' style="color:' . $quotecolour . ';"' : '';
$quoteOpensvg = '<svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
	 width="26.518px" height="14.172px" viewBox="0 0 26.518 14.172" enable-background="new 0 0 26.518 14.172" xml:space="preserve">
<g>
	<g>
		<defs>
			<rect id="SVGID_1_" x="0" y="0" width="26.518" height="14.172"/>
		</defs>
		<clipPath id="SVGID_2_">
			<use xlink:href="#SVGID_1_"  overflow="visible"/>
		</clipPath>
		<path clip-path="url(#SVGID_2_)" fill="' . $quotecolour . '" d="M20.533,3.07V0c-3.534,0-6.398,3.967-6.398,7.5s2.864,6.672,6.398,6.672
			c3.533,0,5.984-3.06,5.984-5.71S24.422,3.129,20.533,3.07"/>
	</g>
	<g>
		<defs>
			<rect id="SVGID_3_" x="0" y="0" width="26.518" height="14.172"/>
		</defs>
		<clipPath id="SVGID_4_">
			<use xlink:href="#SVGID_3_"  overflow="visible"/>
		</clipPath>
		<path clip-path="url(#SVGID_4_)" fill="' . $quotecolour . '" d="M6.399,3.07V0C2.865,0,0.001,3.967,0.001,7.5C0,11.033,2.865,14.172,6.399,14.172
			c3.534,0,5.984-3.06,5.984-5.71S10.288,3.129,6.399,3.07"/>
	</g>
</g>
</svg>';
$quoteClosesvg = '<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
<svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
	 width="26.518px" height="14.173px" viewBox="0 0 26.518 14.173" enable-background="new 0 0 26.518 14.173" xml:space="preserve">
<g>
	<defs>
		<rect id="SVGID_1_" y="0" width="26.518" height="14.173"/>
	</defs>
	<clipPath id="SVGID_2_">
		<use xlink:href="#SVGID_1_"  overflow="visible"/>
	</clipPath>
	<path clip-path="url(#SVGID_2_)" fill="' . $quotecolour . '" d="M5.985,11.103v3.069c3.534,0,6.398-3.966,6.398-7.499
		C12.383,3.14,9.519,0,5.985,0C2.451,0,0,3.06,0,5.71C0,8.361,2.096,11.043,5.985,11.103"/>
	<path clip-path="url(#SVGID_2_)" fill="' . $quotecolour . '" d="M20.119,11.103v3.069c3.534,0,6.398-3.966,6.398-7.499
		C26.518,3.14,23.653,0,20.119,0s-5.984,3.06-5.984,5.71C14.135,8.361,16.23,11.043,20.119,11.103"/>
</g>
</svg>';


$slide = '<div class="cta-quote-slide">';
if (isset($content['field_lp_blk_1'][0]['#markup'])) {
  $slide .='<blockquote' . $quoteTextColourStyle . '><div>' . $quoteOpensvg . '</div>' . $content['field_lp_blk_1'][0]['#markup'] . '<div>' . $quoteClosesvg . '</div></blockquote>';
}
if (isset($content['field_cta_text'][0]['#markup'])) {
  $slide .='<p class="quote-title-1">' . $content['field_cta_text'][0]['#markup'] . '</p>';
}
$slide .= '</div>';
?>
<?php print $slide; ?>
