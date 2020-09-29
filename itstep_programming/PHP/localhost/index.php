<?
session_start(); //Новая или поднять пред
//она привязана к браузеру через session_id
//данные в сессии хранятся на сервере в виде файлов
// позволяют знать серверу про юзера хоть http и stateless
setcookie("name","Vlad",time()+20*24*3600);
$_SESSION['count']++;
echo "<h1>Hello!</h1>";
$a=8;
echo "<p>".$a."</p>";

echo "<p>a.$a.b</p>";
echo '<p>a.$a.b</p>';
?>
<b>test</b>
<?
echo $_GET['a'];
//localhost:89/index.php?a=abbccd
echo "<br>";
print_r($_GET);
//localhost:89/index.php?a=abbccd&b=123
echo "<br>";
echo($_GET);
echo "<br>";
print_r($_POST);
echo "<br>";
print_r($_SESSION);
echo "<br>";
print_r($_COOKIE);
echo "<h2> User name:".$_COOKIE['name']."</h2>";
echo "<br>";

$login = $_POST['login'];
$password=$_POST['password'];

$sql = "SELECT * FROM user WHERE login='$login' AND password='$password'"; // WHERE login='$login' AND password='$password'"

echo $sql;

$mysqli=new mysqli("localhost","root","","webportal");
$result = $mysqli->query($sql);

while($user=$result->fetch_assoc()){
	var_dump($user);
	echo "<br>";
	//' OR 1=1 #
}

?>