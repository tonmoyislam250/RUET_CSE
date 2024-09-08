-- CREATE TABLE Movie_Characters (
--     Character_ID INT PRIMARY KEY,
--     Character_Name VARCHAR(255),
--     Age INT
-- );
-- INSERT INTO Movie_Characters (Character_ID, Character_Name, Age)
-- VALUES (1, 'Apu', 7),
--     (2, 'Durga', 10),
--     (3, 'Harihar', 42),
--     (4, 'Sarbajaya', 35),
--     (5, 'Ramesh', 28),
--     (6, 'Hemnalini', 25),
--     (7, 'Nalinaksha', 30),
--     (8, 'Kamala', 20),
--     (9, 'Shikha', 21),
--     (10, 'Apratim', 26),
--     (11, 'Feluda', 25),
--     (12, 'Maganlal Meghraj', 35),
--     (13, 'Jatayu', 45),
--     (14, 'Topshe', 18),
--     (15, 'Ruku', 6),
--     (16, 'Faruk', 22),
--     (17, 'Bithi', 19),
--     (18, 'Sathi', 24),
--     (19, 'Lalon', NULL),
--     (20, 'Kaluah', 25),
--     (21, 'Siraj Saain', 45),
--     (22, 'Komli', 25),
--     (23, 'Subir Banerjee', NULL),
--     (24, 'Ashima', 24),
--     (25, 'Rashmoni', NULL),
--     (26, 'Somalata', 24),
--     (27, 'Chaitali', 18),
--     (28, 'Byomkesh Bakshi', 26),
--     (29, 'Ajit', 27),
--     (30, 'Malati', 16),
--     (31, 'Debkumar', 50),
--     (32, 'Doctor Anukul', 45),
--     (33, 'Prabhat', 27),
--     (34, 'Satyabati', 22),
--     (35, 'Anadi Babu', 55),
--     (36, 'PK', NULL),
--     (37, 'Jaggu', 26),
--     (38, 'Sarfaraz', 29),
--     (39, 'Tapasvi Maharaj', 50);

-- CREATE TABLE Movie_Character_Relationship (
--     Character_ID INT,
--     Movie_ID INT,
--     PRIMARY KEY (Character_ID, Movie_ID),
--     FOREIGN KEY (Character_ID) REFERENCES Movie_Characters(Character_ID),
--     FOREIGN KEY (Movie_ID) REFERENCES Movie(Movie_ID)
-- );
-- INSERT INTO Movie_Character_Relationship (Character_ID, Movie_ID)
-- VALUES (1, 1),
--     (2, 1),
--     (3, 1),
--     (4, 1),
--     (5, 2),
--     (6, 2),
--     (7, 2),
--     (8, 2),
--     (9, 3),
--     (10, 3),
--     (11, 4),
--     (12, 4),
--     (13, 4),
--     (14, 4),
--     (15, 4),
--     (16, 5),
--     (17, 5),
--     (18, 5),
--     (19, 6),
--     (20, 6),
--     (21, 6),
--     (22, 6),
--     (23, 7),
--     (24, 7),
--     (25, 8),
--     (26, 8),
--     (27, 8),
--     (28, 9),
--     (28, 10),
--     (29, 9),
--     (29, 10),
--     (30, 9),
--     (31, 9),
--     (32, 9),
--     (33, 10),
--     (34, 9),
--     (34, 10),
--     (35, 10),
--     (36, 11),
--     (37, 11),
--     (38, 11),
--     (39, 11);

SELECT * FROM movie_characters;

-- Query 1.1: Find the name and age of all the movie-characters who are
-- not teenagers.

SELECT Character_Name, Age
FROM movie_characters
WHERE Age > 13 AND Age < 19;

-- Query 1.2: Find the movie ID of all the movies and the number of
-- movie-characters in each movie.
SELECT 
    Movie_ID, 
    COUNT(Character_ID) AS Character_Count
FROM 
    Movie_Character_Relationship
GROUP BY 
    Movie_ID;


-- 1.3 Find the movie name of all the movies and the number
-- of movie characters in each movie.
SELECT 
    M.Movie_Name, 
    COUNT(MCR.Character_ID) AS Character_Count
FROM 
    Movie M
JOIN 
    Movie_Character_Relationship MCR ON M.Movie_ID = MCR.Movie_ID
GROUP BY 
    M.Movie_Name;


-- Query 1.4: Find the name, year of release, IMDB rating, and the name of the director of all the movies that 
-- contain at most 12 characters (including spaces) in their name.

SELECT * FROM movie;

SELECT 
    Movie_Name, 
    Year, 
    IMDB_Rating, 
    Director_Name
FROM 
    Movie
WHERE 
    LENGTH(Movie_Name) <= 12;

-- 1.5 Display the name and the IMDb rating of the movie with
-- the highest IMDb rating in each genre.

SELECT 
    M.Genre, 
    M.Movie_Name, 
    M.IMDB_Rating
FROM 
    Movie M
JOIN 
    (SELECT Genre, MAX(IMDB_Rating) AS Max_Rating
     FROM Movie
     GROUP BY Genre) G 
     ON M.Genre = G.Genre AND M.IMDB_Rating = G.Max_Rating;
