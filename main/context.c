#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#include "esp_err.h"

#include "context.h"
#include "error.h"

#define context_set(p, v, f)  \
    do {                      \
        if ((p) != (v)) {     \
            (p) = (v);        \
            bitsToSet |= (f); \
        }                     \
    } while (0)

#define context_set_flags(c, v, f)                       \
    do {                                                 \
        if (v) {                                         \
            xEventGroupSetBits((c)->event_group, (f));   \
        } else {                                         \
            xEventGroupClearBits((c)->event_group, (f)); \
        }                                                \
    } while (0)

static const char *TAG = "context";

context_t *context_create(void)
{
    context_t *context = calloc(1, sizeof(context_t));

    portMUX_TYPE spinlock = portMUX_INITIALIZER_UNLOCKED;
    context->spinlock = spinlock;
    context->event_group = xEventGroupCreate();

    context->sensors.temp = CONTEXT_UNKNOWN_VALUE;
    context->sensors.humidity = CONTEXT_UNKNOWN_VALUE;

    context->rmt.auto_on.enable = false;
    context->rmt.auto_off.enable = false;

    return context;
}

inline void context_lock(context_t *context)
{
    portENTER_CRITICAL(&context->spinlock);
}

inline void context_unlock(context_t *context)
{
    portEXIT_CRITICAL(&context->spinlock);
}

esp_err_t context_set_temp_humidity(context_t *context, float temp, float humidity)
{
    EventBits_t bitsToSet = 0U;
    context_lock(context);
    context_set(context->sensors.temp, temp, CONTEXT_EVENT_TEMPERATURE);
    context_set(context->sensors.humidity, humidity, CONTEXT_EVENT_HUMIDITY);
    context_unlock(context);

    if (bitsToSet) xEventGroupSetBits(context->event_group, bitsToSet);
    return ESP_OK;
}

esp_err_t context_set_wifi_provisioned(context_t *context)
{
    ARG_CHECK(context != NULL, ERR_PARAM_NULL);
    xEventGroupSetBits(context->event_group, CONTEXT_EVENT_WIFI);
    return ESP_OK;
}

esp_err_t context_set_network_connected(context_t *context, bool connected)
{
    ARG_CHECK(context != NULL, ERR_PARAM_NULL);
    context_set_flags(context, connected, CONTEXT_EVENT_NETWORK);
    return ESP_OK;
}

esp_err_t context_set_network_error(context_t *context, bool error)
{
    ARG_CHECK(context != NULL, ERR_PARAM_NULL);
    context_set_flags(context, error, CONTEXT_EVENT_NETWORK_ERROR);
    return ESP_OK;
}

esp_err_t context_set_time_updated(context_t *context)
{
    ARG_CHECK(context != NULL, ERR_PARAM_NULL);
    xEventGroupSetBits(context->event_group, CONTEXT_EVENT_TIME);
    return ESP_OK;
}

esp_err_t context_set_iot_connected(context_t *context, bool connected)
{
    ARG_CHECK(context != NULL, ERR_PARAM_NULL);
    context_set_flags(context, connected, CONTEXT_EVENT_IOT);
    return ESP_OK;
}

esp_err_t context_set_config(context_t *context, const char *device_id, const char *ssid, const char *password)
{
    ARG_CHECK(context != NULL, ERR_PARAM_NULL);

    EventBits_t bitsToSet = 0U;
    context_lock(context);
    context_set(context->config.device_id, device_id, CONTEXT_EVENT_CONFIG);
    context_set(context->config.ssid, ssid, CONTEXT_EVENT_CONFIG);
    context_set(context->config.password, password, CONTEXT_EVENT_CONFIG);
    context_unlock(context);

    if (bitsToSet) xEventGroupSetBits(context->event_group, bitsToSet);
    return ESP_OK;
}

esp_err_t context_set_rmt_auto_on(context_t *context, bool enable,
                                  int rmt_id, float temp)
{
    EventBits_t bitsToSet = 0U;
    context_lock(context);
    context_set(context->rmt.auto_on.enable, enable, CONTEXT_EVENT_CONFIG);
    context_set(context->rmt.auto_on.rmt_id, rmt_id, CONTEXT_EVENT_CONFIG);
    context_set(context->rmt.auto_on.temp, temp, CONTEXT_EVENT_CONFIG);
    context_unlock(context);
    return ESP_OK;
}

esp_err_t context_set_rmt_auto_off(context_t *context, bool enable,
                                   int rmt_id, float temp)
{
    EventBits_t bitsToSet = 0U;
    context_lock(context);
    context_set(context->rmt.auto_off.enable, enable, CONTEXT_EVENT_CONFIG);
    context_set(context->rmt.auto_off.rmt_id, rmt_id, CONTEXT_EVENT_CONFIG);
    context_set(context->rmt.auto_off.temp, temp, CONTEXT_EVENT_CONFIG);
    context_unlock(context);
    return ESP_OK;
}