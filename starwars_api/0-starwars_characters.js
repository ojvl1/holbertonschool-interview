#!/usr/bin/node

const request = require("request");

const movieId = process.argv[2];
const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
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

  // Fetch and print character names one per line
  characters.forEach((characterUrl) => {
    request(characterUrl, (error, response, body) => {
      if (error) {
        console.error("Error:", error);
        return;
      }

      if (response.statusCode !== 200) {
        console.error("Failed to fetch character:", response.statusCode);
        return;
      }

      const character = JSON.parse(body);
      console.log(character.name);
    });
  });
});
