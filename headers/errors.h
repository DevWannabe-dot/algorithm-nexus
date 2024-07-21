/**
 * @file    errors.h
 * @brief   Auxiliary header with status codes
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2023-12-12
 */

#pragma once

#ifndef __ERRORS_h__
#define __ERRORS_h__

/* Constants */
#define SUCCESS             (0)
#define ARG_ERR_OFFSET      (0)
#define NO_ARGS_PROVIDED    (ARG_ERR_OFFSET + 1)
#define NOT_ENOUGH_ARGS     (ARG_ERR_OFFSET + 2)

#endif