const puppeteer = require("puppeteer");

(async () => {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();

  // Navigate to the registration page
  await page.goto("https://www.register2park.com/register");

  // Type in 'park place'
  await page.waitForSelector("input#searchInput", { timeout: 10000 }); // Wait for up to 10 seconds
  await page.type("input#searchInput", "park place");

  // Wait for search results to load
  await page.waitForSelector(".search-results-item");

  // Select the first option
  await page.click(".search-results-item:first-child");

  // Handle the popup (if there is one)
  await page.waitForSelector(".popup-button-continue");
  await page.click(".popup-button-continue");

  // Select visitor parking
  await page.waitForSelector('input[value="visitor"]');
  await page.click('input[value="visitor"]');

  // Wait for 0.5 seconds
  await page.waitForTimeout(500);

  // Fill up the form fields
  await page.type('input[name="apartmentNumber"]', "123");
  await page.type('input[name="make"]', "Toyota");
  await page.type('input[name="model"]', "Camry");
  await page.type('input[name="licensePlate"]', "ABC123");
  await page.type('input[name="confirmLicensePlate"]', "ABC123");

  // Click on 'next'
  await page.click('button[type="submit"]');

  // Close the browser
  await browser.close();
})();
