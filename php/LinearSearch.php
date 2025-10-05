<?php
function linearSearch($arr, $target) {
    foreach ($arr as $index => $value) {
        if ($value == $target) {
            return $index; // found
        }
    }
    return -1; // not found
}

// Example array
$arr = [12, 34, 54, 2, 3];

// Element to search
$target = 54;

// Perform search
$result = linearSearch($arr, $target);

// Display results in a user-friendly way
echo "Searching for $target in the array: [" . implode(", ", $arr) . "]\n\n";

if ($result != -1) {
    echo "✅ Found $target at position " . ($result + 1) . " (index $result)";
} else {
    echo "❌ Sorry, $target was not found in the array.";
}
?>
