/* -*- Mode: C++; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#ifndef RR_SYSCALLS_H_
#define RR_SYSCALLS_H_

#include <signal.h>

#include <iostream>
#include <string>

#include "kernel_abi.h"

/**
 * Return the symbolic name of |syscall|, f.e. "read", or "???syscall"
 * if unknown.
 */
std::string syscall_name(int syscall, SupportedArch arch);

/**
 * Return the symbolic name of the PTRACE_EVENT_* |event|, or
 * "???EVENT" if unknown.
 */
const char* ptrace_event_name(int event);

/**
 * Return the symbolic name of the PTRACE_ |request|, or "???REQ" if
 * unknown.
 */
const char* ptrace_req_name(int request);

/**
 * Return the symbolic name of |sig|, f.e. "SIGILL", or "???signal" if
 * unknown.
 */
const char* signal_name(int sig);

/**
 * Return true if this is some kind of sigreturn syscall.
 */
bool is_sigreturn(int syscall, SupportedArch arch);

/**
 * Return the symbolic error name (e.g. "EINVAL") for errno.
 */
std::string errno_name(int err);

/**
 * Return the symbolic name (e.g. "SI_USER") for an si_code.
 */
const char* sicode_name(int code, int sig);

/**
 * Print siginfo on ostream.
 */
std::ostream& operator<<(std::ostream& stream, const siginfo_t& siginfo);

int shm_flags_to_mmap_prot(int flags);

#endif
