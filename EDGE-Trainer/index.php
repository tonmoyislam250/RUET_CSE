<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My PHP App</title>

    <link rel="stylesheet" href="styles/style.css">
</head>
<?php
  include 'db.php';

  ini_set('display_errors', 1);
  ini_set('display_startup_errors', 1);
  error_reporting(E_ALL);
?>
<body>

<?php include 'templates/header.php'; ?>

<div class="user-table">
  <?php include 'templates/user-table.php'; ?>
</div>

<?php include 'templates/footer.php'; ?>

</body>
</html>
