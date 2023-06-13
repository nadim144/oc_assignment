-- MySQL dump 10.13  Distrib 8.0.33, for Win64 (x86_64)
--
-- Host: localhost    Database: oc_assignment
-- ------------------------------------------------------
-- Server version	8.0.33

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `_doctors`
--

DROP TABLE IF EXISTS `_doctors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `_doctors` (
  `id` mediumint NOT NULL AUTO_INCREMENT,
  `fName` varchar(50) DEFAULT NULL,
  `lName` varchar(50) DEFAULT NULL,
  `specialization` varchar(60) DEFAULT NULL,
  `emailid` varchar(100) DEFAULT NULL,
  `mobileno` varchar(50) DEFAULT NULL,
  `location` varchar(50) DEFAULT NULL,
  `state` varchar(50) DEFAULT NULL,
  `country` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `_doctors`
--

LOCK TABLES `_doctors` WRITE;
/*!40000 ALTER TABLE `_doctors` DISABLE KEYS */;
INSERT INTO `_doctors` VALUES (1,'Nadim','Ahmad','Orthopedics','ahmad@gmail.com','9738455404','Supaul','Bihar','INDIA'),(2,'Nasim','Ahmad','Anesthesiology','ahmad@gmail.com','9738455404','Supaul','Bihar','INDIA'),(4,'Eiba','Nadim','Orthopedics','eiba@gmail.com','9738455404','Supaul','Bihar','INDIA'),(5,'Aliya','Rizwan','Pediatrics','aliya@gmail.com','9876500022','Bangalore','Karnataka','INDIA'),(6,'Sumaira','Fatima','Neurology','sumaira@gamil.com','9738455404','Supaul','Bihar','INDIA'),(7,'Lamiya','Fatima','Internal medicine','lamiya@gmail.com','9738455404','Bangalore','Karnatka','INDIA'),(8,'Zaroon','Nasim','Surgeon','zaroon@gmail.com','9738455404','Supaul','Bihar','INDIA'),(9,'saif','Ahmad','Anesthesiology','saif@gmail.com','9738455404','Bangalore','Karnatka','INDIA'),(10,'Ayaan','Ahmad','Pediatrics','ayaan@gmail.com','9738455404','Supaul','Karnatka','INDIA'),(11,'Qaiser','Rizwan','Surgeon','qaiser@gmail.com','9738455404','Bangalore','Karnatka','INDIA'),(12,'Mohamad','Imran','Neurology','imran@gmail.com','9738455404','Supaul','Bihar','INDIA');
/*!40000 ALTER TABLE `_doctors` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-06-12 23:05:33
