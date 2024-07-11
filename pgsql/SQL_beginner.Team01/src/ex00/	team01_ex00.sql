WITH myCurrency AS (
    SELECT currency.id, currency.name, currency.rate_to_usd, currency.updated
    FROM currency
    JOIN (
        SELECT id, name, MAX(updated) AS updated
        FROM currency
        GROUP BY id, name ) AS currencyMin
    ON currency.id = currencyMin.id
    AND currency.updated = currencyMin.updated
    AND currency.name = currencyMin.name
)

SELECT COALESCE("user".name, 'not defined') AS name,
       COALESCE("user".lastname, 'not defined') AS lastname,
       balance.type,
       SUM(balance.money) AS volume,
       COALESCE(myCurrency.name, 'not defined') AS currency_name,
       COALESCE(myCurrency.rate_to_usd, 1) AS last_rate_to_usd,
       COALESCE(myCurrency.rate_to_usd, 1) * SUM(balance.money) AS total_volume_in_usd
FROM "user"
FULL JOIN balance ON "user".id = balance.user_id
FULL JOIN myCurrency ON balance.currency_id = myCurrency.id
GROUP BY "user".name, "user".lastname, balance.type, myCurrency.name, COALESCE(myCurrency.rate_to_usd, 1)
ORDER BY 1 DESC, 2 ASC, 3 ASC;