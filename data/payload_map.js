// @ts-check

const CUSTOM_ACTION_APPCACHE_REMOVE = "appcache-remove";

/**
 * @typedef {Object} PayloadInfo
 * @property {string} displayTitle
 * @property {string} description
 * @property {string} fileName - path relative to the payloads folder
 * @property {string} author
 * @property {string} projectSource
 * @property {string} binarySource - should be direct download link to the included version, so that you can verify the hashes
 * @property {string} version
 * @property {string[]?} [supportedFirmwares] - optional, these are interpreted as prefixes, so "" would match all, and "4." would match 4.xx, if not set, the payload is assumed to be compatible with all firmwares
 * @property {number?} [toPort] - optional, if the payload should be sent to "127.0.0.1:<port>" instead of loading directly, if specified it'll show up in webkit-only mode too
 * @property {string?} [customAction]
 */

/**
 * @type {PayloadInfo[]}
*/
const payload_map = [
  {
    displayTitle: "byepervisor",
    description: "FPKG enabler",
    fileName: "byepervisor.elf",
    author: "SpecterDev, ChendoChap, flatz, fail0verflow, Znullptr, kiwidog, sleirsgoevy, EchoStretch, LightningMods, BestPig, zecoxao", 
    projectSource: "https://github.com/EchoStretch/Byepervisor",
    binarySource: "https://github.com/EchoStretch/Byepervisor/actions/runs/14004003762",
    version: "84164bb",
    supportedFirmwares: ["1.00", "1.01", "1.02", "1.12", "1.14", "2.00", "2.20", "2.25", "2.26", "2.30", "2.50", "2.70"],
    toPort: 9021
  },
  {
    displayTitle: "etaHEN",
    description: "AIO Homebrew enabler",
    fileName: "etaHEN.bin.gz",
    author: "LightningMods, Buzzer, sleirsgoevy, ChendoChap, astrelsky, illusion, CTN, SiSTR0, Nomadic",
    projectSource: "https://github.com/etaHEN/etaHEN",
    binarySource: "https://github.com/etaHEN/etaHEN/blob/ea3b04a60f911d31e3888a0f98a57b3cccfe787c/etaHEN-2.1B.bin",
    version: "2.1b",
    toPort: 9021
  },
  {
    displayTitle: "kstuff",
    description: "FPKG enabler",
    fileName: "kstuff.elf.gz",
    author: "sleirsgoevy, john-tornblom, EchoStretch, buzzer-re, BestPig, LightningMods, zecoxao",
    projectSource: "https://github.com/EchoStretch/kstuff",
    binarySource: "https://github.com/EchoStretch/kstuff/actions/runs/14825864251",
    version: "1.5",
    supportedFirmwares: ["3.", "4.", "5."],
    toPort: 9021
  },
  {
    displayTitle: "kstuff-toggle",
    description: "FPKG enabler toggle",
    fileName: "kstuff-toggle.elf",
    author: "EchoStretch",
    projectSource: "https://github.com/EchoStretch/kstuff-toggle",
    binarySource: "https://github.com/EchoStretch/kstuff-toggle/actions/runs/14787109677",
    version: "0.1b",
    supportedFirmwares: ["3.", "4.", "5."],
    toPort: 9021
  },
  {
    displayTitle: "ftpsrv",
    description: "FTP server. Runs on port 2121.",
    fileName: "ftpsrv.elf",
    author: "john-tornblom",
    projectSource: "https://github.com/ps5-payload-dev/ftpsrv",
    binarySource: "https://github.com/ps5-payload-dev/pacbrew-repo/actions/runs/14012252230",
    version: "0.11.3",
    toPort: 9021
  },
  {
    displayTitle: "webkit-cache-remover",
    description: "Removes the WebKit cache for all users.",
    fileName: "webkit-cache-remover.elf",
    author: "vladimir-cucu",
    projectSource: "https://github.com/vladimir-cucu/ps5-webkit-cache-remover",
    binarySource: "https://github.com/vladimir-cucu/ps5-webkit-cache-remover/releases/tag/v1.01",
    version: "1.01",
    toPort: 9021
  }
];
