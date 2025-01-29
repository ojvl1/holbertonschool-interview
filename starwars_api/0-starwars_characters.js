#!/usr/bin/node

const request = require("request");

const movieId = process.argv[2];
const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, async (error, response, body) => {
  if (error) {
    console.error("Error:", error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error("Failed to fetch data:", response.statusCode);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  // Function to fetch character name in order
  const fetchCharacterName = (url) => {
    return new Promise((resolve, reject) => {
      request(url, (error, response, body) => {
        if (error) {
          reject(error);
          return;
        }
        if (response.statusCode !== 200) {
          reject(`Failed to fetch character: ${response.statusCode}`);
          return;
        }
        const character = JSON.parse(body);
        resolve(character.name);
      });
    });
  };

  // Fetch characters sequentially
  for (const url of characters) {
    try {
      const name = await fetchCharacterName(url);
      console.log(name);
    } catch (err) {
      console.error("Error:", err);
    }
  }
});
