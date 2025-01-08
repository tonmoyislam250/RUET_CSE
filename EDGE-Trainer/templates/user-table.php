<?php
$search = $_GET['search'] ?? '';
$orderByField = $_GET['order_by'] ?? 'id';
$orderDirection = $_GET['direction'] ?? 'ASC';
$limit = (int)($_GET['limit'] ?? 10);
$page = (int)($_GET['page'] ?? 1);
$page = max($page, 1);
$offset = ($page - 1) * $limit;

$filter = !empty($search) ? "WHERE name LIKE '%" . $conn->real_escape_string($search) . "%'" : "";

$orderDirection = strtoupper($orderDirection) === 'DESC' ? 'DESC' : 'ASC';

$totalQuery = "SELECT COUNT(*) AS total FROM user $filter";
$totalResult = $conn->query($totalQuery);
$totalRecords = $totalResult->fetch_assoc()['total'];
$totalPages = ceil($totalRecords / $limit);

$sql = "SELECT * FROM user $filter ORDER BY $orderByField $orderDirection LIMIT $offset, $limit";
$result = $conn->query($sql);
?>

<h1>User Search and Pagination</h1>

<form method="GET">
    <label for="search">Search by Name:</label>
    <input type="text" id="search" name="search" value="<?= htmlspecialchars($search) ?>" placeholder="Enter name">
    
    <label for="order_by">Order By:</label>
    <select id="order_by" name="order_by">
        <option value="id" <?= $orderByField === 'id' ? 'selected' : '' ?>>ID</option>
        <option value="name" <?= $orderByField === 'name' ? 'selected' : '' ?>>Name</option>
    </select>
    
    <label for="direction">Direction:</label>
    <select id="direction" name="direction">
        <option value="ASC" <?= $orderDirection === 'ASC' ? 'selected' : '' ?>>Ascending</option>
        <option value="DESC" <?= $orderDirection === 'DESC' ? 'selected' : '' ?>>Descending</option>
    </select>
    
    <label for="limit">Records Per Page:</label>
    <select id="limit" name="limit">
        <option value="5" <?= $limit === 5 ? 'selected' : '' ?>>5</option>
        <option value="10" <?= $limit === 10 ? 'selected' : '' ?>>10</option>
        <option value="20" <?= $limit === 20 ? 'selected' : '' ?>>20</option>
        <option value="50" <?= $limit === 50 ? 'selected' : '' ?>>50</option>
    </select>
    
    <button type="submit">Filter</button>
</form>

<table>
    <tr>
        <th>ID</th>
        <th>Name</th>
    </tr>
    <?php if ($result->num_rows > 0): ?>
        <?php while ($row = $result->fetch_assoc()): ?>
            <tr>
                <td><?= htmlspecialchars($row['id']) ?></td>
                <td><?= htmlspecialchars($row['name']) ?></td>
            </tr>
        <?php endwhile; ?>
    <?php else: ?>
        <tr>
            <td colspan="2">No matching records found</td>
        </tr>
    <?php endif; ?>
</table>

<div class="pagination">
    <?php if ($page > 1): ?>
        <a href="?<?= http_build_query(array_merge($_GET, ['page' => $page - 1])) ?>">Previous</a>
    <?php endif; ?>
    <?php for ($i = 1; $i <= $totalPages; $i++): ?>
        <a href="?<?= http_build_query(array_merge($_GET, ['page' => $i])) ?>" class="<?= $i === $page ? 'active' : '' ?>">
            <?= $i ?>
        </a>
    <?php endfor; ?>
    <?php if ($page < $totalPages): ?>
        <a href="?<?= http_build_query(array_merge($_GET, ['page' => $page + 1])) ?>">Next</a>
    <?php endif; ?>
</div>
